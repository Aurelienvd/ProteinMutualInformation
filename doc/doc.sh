#! /bin/bash
doxygen protein_information_doc
if [ -e "./index.html" ]; 
then
	rm ./index.html
fi
ln --symbolic html/index.html ./index.html
