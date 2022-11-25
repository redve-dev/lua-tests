add = function(a, b)
	return a+b
end

-- Newton-Rawson algorithm
sqrt = function(n, epsilon)
	local a=n
	local b=1
	while ( math.abs(a-b) >= epsilon )
		do
			a=(a+b)/2
			b=n/a
		end
	return a
end
