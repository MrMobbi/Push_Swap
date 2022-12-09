b = []
ARGV[0].to_i.times { |i|
	c = rand(-5000..5000)
	while b.include?(c)
		c = rand(-5000..5000)
	end
	b.append(c)
}
a = b.shuffle
print a.join(' ')
