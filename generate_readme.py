#!/usr/bin/env python3
"""
Generates README.md from problems.json.

Usage:
    python generate_readme.py

This script is called locally and by GitHub Actions after classify.py runs.
Do not edit README.md manually — it will be overwritten.
"""

import json
from collections import defaultdict
from pathlib import Path

# ── Config ─────────────────────────────────────────────────────────────────────

PROBLEMS_FILE = Path("problems.json")
README_FILE   = Path("README.md")
REPO_URL      = "https://github.com/dkesslerm/daily-coding-problem/blob/main"

EMOJI = {"easy": "🟢", "medium": "🟡", "hard": "🔴"}

# Preferred display order for topics
TOPIC_ORDER = [
    "arrays", "strings", "hash-table", "two-pointers", "sliding-window",
    "linked-lists", "stack", "queue",
    "trees", "graphs", "heap",
    "binary-search", "sorting",
    "dynamic-programming", "recursion", "backtracking",
    "greedy", "math", "bit-manipulation", "matrix", "other",
]

# ── Helpers ────────────────────────────────────────────────────────────────────

def topic_display(topic: str) -> str:
    return topic.replace("-", " ").title()


def file_link(file_path: str) -> str:
    filename = Path(file_path).name
    return f"[`{filename}`]({REPO_URL}/{file_path})"


def difficulty_cell(difficulty: str) -> str:
    return f"{EMOJI.get(difficulty, '⚪')} {difficulty.capitalize()}"


# ── Generator ──────────────────────────────────────────────────────────────────

def generate_readme() -> None:
    if not PROBLEMS_FILE.exists():
        print("problems.json not found. Run classify.py first.")
        return

    data     = json.loads(PROBLEMS_FILE.read_text(encoding="utf-8"))
    problems = data.get("problems", [])

    if not problems:
        print("No problems found in problems.json.")
        return

    # ── Stats ──────────────────────────────────────────────────────────────────
    counts: dict[str, int] = defaultdict(int)
    for p in problems:
        counts[p["difficulty"]] += 1
    total = len(problems)

    # ── Group by topic ─────────────────────────────────────────────────────────
    by_topic: dict[str, list] = defaultdict(list)
    for p in problems:
        for t in p.get("topics", ["other"]):
            by_topic[t].append(p)

    # Sort topics: follow TOPIC_ORDER, then alphabetically for any extras
    known_order   = [t for t in TOPIC_ORDER if t in by_topic]
    extra_topics  = sorted(t for t in by_topic if t not in TOPIC_ORDER)
    ordered_topics = known_order + extra_topics

    # ── Build lines ────────────────────────────────────────────────────────────
    lines: list[str] = []

    # Header
    lines += [
        "# Daily Coding Problem — Solutions",
        "",
        "> C++ solutions to the [Daily Coding Problem](https://www.dailycodingproblem.com/) newsletter.",
        "> *README is auto-generated — do not edit manually.*",
        "",
    ]

    # Stats
    lines += [
        "## 📊 Stats",
        "",
        f"| 🟢 Easy | 🟡 Medium | 🔴 Hard | Total |",
        f"|---------|-----------|---------|-------|",
        f"| {counts['easy']} | {counts['medium']} | {counts['hard']} | **{total}** |",
        "",
    ]

    # By Topic (collapsible sections)
    lines += ["## 🏷️ By Topic", ""]

    for topic in ordered_topics:
        topic_problems = sorted(
            by_topic[topic],
            key=lambda p: (p["difficulty"], p["file"])
        )
        lines.append(f"<details>")
        lines.append(
            f"<summary><b>{topic_display(topic)}</b> "
            f"&nbsp;·&nbsp; {len(topic_problems)} problem(s)</summary>"
        )
        lines.append("")
        lines.append("| Problem | Difficulty | File |")
        lines.append("|---------|------------|------|")
        for p in topic_problems:
            lines.append(
                f"| {p['title']} "
                f"| {difficulty_cell(p['difficulty'])} "
                f"| {file_link(p['file'])} |"
            )
        lines.append("")
        lines.append("</details>")
        lines.append("")

    # Full table
    lines += [
        "## 📋 All Problems",
        "",
        "| Problem | Topics | Difficulty | File |",
        "|---------|--------|------------|------|",
    ]

    sorted_problems = sorted(problems, key=lambda p: (p["difficulty"], p["file"]))
    for p in sorted_problems:
        tags = " ".join(f"`{t}`" for t in p.get("topics", []))
        lines.append(
            f"| {p['title']} "
            f"| {tags} "
            f"| {difficulty_cell(p['difficulty'])} "
            f"| {file_link(p['file'])} |"
        )

    lines.append("")   # Trailing newline

    # ── Write ──────────────────────────────────────────────────────────────────
    README_FILE.write_text("\n".join(lines), encoding="utf-8")
    print(
        f"✅ README.md generated — "
        f"{counts['easy']} easy / {counts['medium']} medium / {counts['hard']} hard "
        f"({total} total)."
    )


if __name__ == "__main__":
    generate_readme()
