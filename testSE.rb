require 'numo/narray'
include Numo

Sci=Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
puts "理科"
puts "理科の平均#{Sci.mean}"
puts "理科の標準偏差#{Sci.stddev}"
puts "理科の合計点#{Sci.sum}"
ary = Sci.sort
20.times do |i|
	print "#{ary[i]},"
end
puts "" 
20.times do |i|
	hen = (Sci.mean - Sci[i]) * 10 / Sci.stddev
	if hen > Sci.mean then
		sati = 50 + hen
	elsif hen < Sci.mean then
		sati = 50 - hen
	else sati = 50
	end
	puts "#{i+1}人目の理科偏差値は#{sati}"
end

Eng=Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]
puts "英語"
puts "英語の平均点#{Eng.mean}"
puts "英語の標準偏差#{Eng.stddev}"
puts "英語の合計点#{Eng.sum}"
yra = Eng.sort
20.times do |j|
	print "#{yra[j]},"
end
puts""	
20.times do |j|
	neh = (Eng.mean - Eng[j]) * 10 / Eng.stddev 

	if neh > Eng.mean then
		itas = 50 + neh
	elsif neh < Eng.mean then
		itas = 50 - neh
	else itas = 50
	end
	puts "#{j+1}人目の英語偏差値は#{itas}"
end
