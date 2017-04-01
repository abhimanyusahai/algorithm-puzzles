class SumOfMultiples
  def initialize(*numbers)
    @numbers = numbers
  end

  def self.to(max)
    SumOfMultiples.new(3,5).to(max)
  end

  def to(max)
    multiples = [0]
    @numbers.each { |number| multiples << (number..(max - 1)).step(number).to_a }
    multiples.flatten.uniq.reduce(:+)
  end
end
