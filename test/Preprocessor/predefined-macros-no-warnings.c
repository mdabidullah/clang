// Check that the predefined macros don't contain anything that causes a
// warning, which needs -Wsystem-headers to detect as the predefined macros
// are in the <built-in> file which is treated as a system header and so has
// warnings suppressed by default.
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple xcore
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple hexagon
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple hexagon-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple lanai
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64_32-darwin
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-darwin
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-fuchsia
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-linux-openhos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-win32-gnu
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64-win32-msvc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64_be
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64_be-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64_be-fuchsia
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64_be-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple aarch64_be-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-darwin
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-fuchsia
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-linux-openhos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-liteos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-nacl
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-win32-cygnus
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-win32-gnu
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-win32-itanium
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple arm-win32-msvc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple armeb
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple armeb-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple armeb-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple armeb-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple armeb-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple armeb-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple avr
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple bpfeb
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple bpfel
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple msp430
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel-linux-openhos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mipsel-nacl
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64el
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64el-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64el-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64el-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64el-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple mips64el-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple m68k
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple m68k-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple m68k-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple le32-nacl
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple le64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc-aix
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppcle
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppcle-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppcle-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64-lv2
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64-aix
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64le-
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64le-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64le-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64le-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ppc64le-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple nvptx
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple nvptx64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple amdgcn
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple r600
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv32
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv32-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv64-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv64-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv64-fuchsia
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv64-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple riscv64-linux-openhos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparc-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparc-solaris
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparc-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparc-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcel
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcel-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcel-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcel-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-solaris
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-systemz
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple sparcv9-zos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple tce
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple tcele
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-darwin
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-linux-android
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-dragonfly
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-fuchsia
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-kfreebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-solaris
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-win32-cygnus
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-win32-gnu
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-win32-itanium
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-win32-msvc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-haiku
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-rtems
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-nacl
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-elfiamcu
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple i686-hurd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-darwin
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-linux-android
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-linux-openhos
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-dragonfly
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-netbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-openbsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-freebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-fuchsia
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-kfreebsd
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-solaris
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-win32cygnus
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-win32gnu
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-win32msvc
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-haiku
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-nacl
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-ps4
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple x86_64-ps5
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple spir
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple spir64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple spirv32
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple spirv64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple wasm32
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple wasm32-wasi
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple wasm32-emscripten
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple wasm64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple wasm64-wasi
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple wasm64-emscripten
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple dxil
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple renderscript32
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple renderscript64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple ve
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple csky
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple csky-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple loongarch32
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple loongarch32-linux
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple loongarch64
// RUN: %clang_cc1 %s -Eonly -Wsystem-headers -Werror -triple loongarch64-linux
