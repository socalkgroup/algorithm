n = length of sequence
i,j,k=0 //Initialize
ug[0] = 1 //Set first ug number
while length(ug) < n
begin
	ug2 = ug[i]  * 2
	ug3 = ug[j]  * 3
	ug5 = ug[k] * 5
	next_ug = minimum(ug2, ug3, ug5)
	ug.append(next_ug)
	if next_ug == ug2
		i++
if next_ug == ug3
		j++
if next_ug == ug5
		k++
end
return ug
