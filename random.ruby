b = []
ARGV[0].to_i.times { |i|
	c = rand(-2147483648..2147483647)
	while b.include?(c)
		c = rand(-2147483648..2147483647)
	end
	b.append(c)
}
a = b.shuffle
print a.join(' ')
