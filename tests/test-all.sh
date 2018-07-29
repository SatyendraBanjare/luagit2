#!/bin/bash
 
fix="Fixtures/"
 
for d in */ 
do
  if [ "$d" = "$fix" ]; then
      continue
  else
      echo ''; echo "testing $d" ;echo '';
      busted "$d" -c 
  fi
done   