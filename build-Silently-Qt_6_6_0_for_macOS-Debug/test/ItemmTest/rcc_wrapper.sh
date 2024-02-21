#!/bin/bash
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/ilagoncarenko/Qt/6.6.0/macos/libexec/rcc "$@"
