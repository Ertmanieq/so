(date; ps -ef | grep [c]ron | \
	awk '{print $1 " [" $7 "]" }' | \
	sort | uniq) >> doomed.users
cat doomed.users
