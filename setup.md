---
title: Setup
---

# Setup

We recommend Visual Studio Code (VSCode) as a text editor for this course. We offer setup tutorials and CSE 232-specific configuration files for debugging. You are free to install and work with other text editors, but are responsible for knowing how to use it.

Choose the tutorial that corresponds to your operating system, if wanting to use VSCode:
- [Windows](setup/setup_windows.html)
- [MacOS](setup/setup_macos.html)
- [Linux](setup/setup_linux.html)

These tutorials will have you setup the VSCode debugger. If you are unfamiliar with how to use an IDE debugger, [you can find a brief guide here](debugging_guide.html).

The VSCode debugger relies on a special folder in your workspace called ".vscode". The tutorials briefly explain what it does and why it's necessary. With how VSCode operates at the time of writing, a global .vscode folder for debugging configurations is not a thing, and so you may end up having to copy a .vscode folder in many different places if you want to move workspaces a lot.

[We provide recommended .vscode configurations that can be installed to your terminal's current directory here.](https://github.com/CSE232-MSU/CSE232-VSCCONF) There is also a .gdbinit file that skips over internal C++ code when debugging on Windows; this should only need to be installed once.
