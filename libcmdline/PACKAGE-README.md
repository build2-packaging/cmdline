# libcmdline - C++ command line parser library

This is a `build2` package for the [`cmdline`](https://github.com/tanakh/cmdline)
C++ library. It provides a header-only command line parser with typed options,
generated usage text, and optional value constraints.

This package's `cmdline.h` is a backwards-compatible superset of upstream:
alongside MSVC portability fixes, it adds a few bug fixes (swallowed error
messages, an empty-vector edge case, a Windows macro clash) and some new
opt-in parsing capabilities (stop-at-rest passthrough, a header/footer, and
parsing argv-like lists without a program name). Everything is additive, so
code written against vanilla tanakh/cmdline keeps compiling and behaving the
same.


## Usage

To start using `libcmdline` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcmdline ^0.0.1
```

Then import the library in your `buildfile`:

```
import libs = libcmdline%lib{cmdline}
```


## Importable targets

This package provides the following importable targets:

```
lib{cmdline}
```

Header-only. Include the public header as `#include <cmdline/cmdline.h>`
(or `"cmdline/cmdline.h"`). Upstream ships `cmdline.h` at the repository
root. This package installs it under a `cmdline/` prefix so the header can
coexist with other libraries.


## Configuration variables

This package has no configuration variables.
