"""
To-Do List Application
CodSoft - Python Programming Internship (Task 1)

Simple command-line to-do list manager. Tasks are saved to a JSON file
so the list persists between runs.
"""

import json
import os

DATA_FILE = "tasks.json"


def load_tasks():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, "r") as f:
            return json.load(f)
    return []


def save_tasks(tasks):
    with open(DATA_FILE, "w") as f:
        json.dump(tasks, f, indent=2)


def show_tasks(tasks):
    if not tasks:
        print("\nNo tasks yet!\n")
        return
    print("\nYour Tasks:")
    for i, task in enumerate(tasks, start=1):
        status = "x" if task["done"] else " "
        print(f"  [{status}] {i}. {task['title']}")
    print()


def add_task(tasks):
    title = input("Enter new task: ").strip()
    if title:
        tasks.append({"title": title, "done": False})
        save_tasks(tasks)
        print("Task added.\n")


def complete_task(tasks):
    show_tasks(tasks)
    try:
        idx = int(input("Enter task number to mark complete: ")) - 1
        tasks[idx]["done"] = True
        save_tasks(tasks)
        print("Task marked complete.\n")
    except (ValueError, IndexError):
        print("Invalid task number.\n")


def delete_task(tasks):
    show_tasks(tasks)
    try:
        idx = int(input("Enter task number to delete: ")) - 1
        removed = tasks.pop(idx)
        save_tasks(tasks)
        print(f"Deleted: {removed['title']}\n")
    except (ValueError, IndexError):
        print("Invalid task number.\n")


def main():
    tasks = load_tasks()
    menu = """
1. View tasks
2. Add task
3. Mark task complete
4. Delete task
5. Exit
"""
    while True:
        print(menu)
        choice = input("Choose an option: ").strip()
        if choice == "1":
            show_tasks(tasks)
        elif choice == "2":
            add_task(tasks)
        elif choice == "3":
            complete_task(tasks)
        elif choice == "4":
            delete_task(tasks)
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid option, try again.\n")


if __name__ == "__main__":
    main()
