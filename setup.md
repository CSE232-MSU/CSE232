---
title: VSCode Setup
---

# VSCode Setup

We recommend Visual Studio Code (VSCode) as a text editor for this course. We offer setup tutorials and CSE 232-specific configuration files for debugging. You are free to install and work with other text editors, but are responsible for knowing how to use it.

Choose the tutorial that corresponds to your operating system, if wanting to use VSCode:
- [Windows](setup/setup_windows.html)
- [MacOS](setup/setup_macos.html)
- [Linux](setup/setup_linux.html)

These tutorials will have you setup the VSCode debugger. If you are unfamiliar with how to use an IDE debugger, [you can find a brief guide here](debugging_guide.html).

The VSCode debugger relies on a special folder in your workspace called ".vscode". The tutorials briefly explain what it does and why it's necessary. With how VSCode operates at the time of writing, a global .vscode folder for debugging configurations is not a thing, and so you may end up having to copy a .vscode folder in many different places if you want to move workspaces a lot.

[We provide recommended .vscode configurations that can be installed to your terminal's current directory here.](https://github.com/CSE232-MSU/CSE232-VSCCONF) There is also a .gdbinit file that skips over internal C++ code when debugging on Windows; this should only need to be installed once.

## Alternatives

There are _many_ text editors out there that you are absolutely welcome to use, but again, responsibility for knowing your text editor will fall on you because we (Dr. Nahum and the TAs) may have no knowledge of how to use it. 

If you ever need a backup editor at any point during this course (maybe your text editor installation is corrupted, a raunchy update was pushed out for it), then we recommend using [Replit](https://replit.com/~). Replit is a free browser-based IDE that provides C++ features, a debugger, Linux-command line tools, and Google Doc-like collaboration features. This should be treated purely as a _backup_, because Replit can become slow with larger programs.

Other text editors you may be interested in:
- [Visual Studio](https://visualstudio.microsoft.com/) - Not to be confused with _Visual Studio Code_. This is an absolute unit of a text editor that is primarily intended for Windows application development. Students have used it for this class, too, though.
- [Xcode](https://developer.apple.com/xcode/) - A MacOS-exclusive text editor developed by Apple. This, again, is primarily intended for MacOS/iOS application development, but students have used it in the past.
- [Vim](https://www.vim.org/download.php) - A terminal-based text editor that comes packaged with most Linux systems. Has a _ton_ of keybindings, but, when mastered, can be used to write code at an incredible pace. Could be a fun thing to learn on the side, but not recommended as a first text editor.
