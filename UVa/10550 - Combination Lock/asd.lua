function degrees(s, e, clockwise)
	diff = 0;
	if clockwise != 1 then
		if e > s then
			diff = e - s
		else
			diff = 40 - (s - e)
		end
	else
		if s > e then
			diff = s - e
		else
			diff = 40 - (e - s)
		end
	end
	print("diff is " .. diff)
	return diff * 9
end
