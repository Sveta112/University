#!/bin/sh
basedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")

case `uname` in
    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;
esac

if [ -x "$basedir/node" ]; then
  "$basedir/node"  "$basedir/node_modules/requirejs/bin/r.js" "$@"
  ret=$?
else 
  node  "$basedir/node_modules/requirejs/bin/r.js" "$@"
  ret=$?
fi
exit $ret
