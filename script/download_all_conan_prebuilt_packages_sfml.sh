#!/usr/bin/env sh

wget -e robots=off -U mozilla -r "https://dl.bintray.com/bincrafters/public-conan/bincrafters/sfml/2.5.1/stable/0"

# time for me: 1h 11m 17s
# Downloaded: 7123 files, 1.3G

grep -oPzlr '(?s)audio=True.*?graphics=True'

