#! /bin/bash
doxygen protein_information_doc
ln --symbolic html/index.html ./index.html
