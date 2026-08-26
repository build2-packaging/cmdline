# cmdline - C++ command line parser library

This is a `build2` package repository for [`cmdline`](https://github.com/tanakh/cmdline),
a header-only C++ command line parser.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`cmdline` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libcmdline/PACKAGE-README.md) file.

The development setup for `cmdline` uses the standard `bdep`-based workflow.
For example:

```
git clone --recursive https://github.com/build2-packaging/cmdline.git
cd cmdline

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
