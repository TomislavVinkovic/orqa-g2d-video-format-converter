#!/bin/bash

REPORT_FILE="tidify_report.txt"

[ -f "$REPORT_FILE" ] && rm "$REPORT_FILE"

make -j16 -f tidify_all.mk

filesize=$(du -sb tidify_report.txt | awk '{print $1}')

if [ $filesize = 0 ]; then
    echo "+------------+"
    echo "| No issues. |"
    echo "+------------+"
    rm -r tidify_report.txt
else
    echo "+--------------------------+"
    echo "| Clang tidy found issues. |"
    echo "| Please fix all issues.   |"
    echo "+--------------------------+"
fi

rm -r ct
