SHELL := /bin/bash
APPNAME := utilities_forms

VERSION := $(shell cat VERSION | tr -d "[:space:]")

default: clean compile package

clean:
	rm -Rf build/${APPNAME}*

compile:
	cd public/css && cp global.css global-${VERSION}.css
	cd public/css && cp onbase.css onbase-${VERSION}.css
	cd public/js  && cp global.js  global-${VERSION}.js
	cd public/js  && cp onbase.js  onbase-${VERSION}.js
	cd public/js  && cp addressChooser.js addressChooser-${VERSION}.js

package:
	[[ -d build ]] || mkdir build
	rsync -rl --exclude-from=buildignore . build/${APPNAME}
	cd build && tar czf ${APPNAME}-${VERSION}.tar.gz ${APPNAME}
