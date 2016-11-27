find /home -user $1 -fstype ext3 -ls 2>/dev/null | awk \
	'{sum+=$7}; END {print "Total disk use = " sum/1024 "Kb"}'
