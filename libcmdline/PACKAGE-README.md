# libcmdline - C++ command line parser library

This is a `build2` package for the [`cmdline`](https://github.com/tanakh/cmdline)
C++ library. It provides a header-only command line parser with typed options,
generated usage text, and optional value constraints.


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
