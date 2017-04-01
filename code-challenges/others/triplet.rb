class Triplet
  def initialize(a, b, c)
    @a = a
    @b = b
    @c = c
  end

  def sum
    @a + @b + @c
  end

  def product
    @a * @b * @c
  end

  def pythagorean?
    @a ** 2 + @b ** 2 == @c ** 2
  end

  def self.where(options)
    triplets = []
    min = options[:min_factor].nil? ? 1 : options[:min_factor]
    max = options[:max_factor]
    (min..max).each do |n|
      ((n + 1)..max).each do |m|
        if sqrt(n ** 2 + m ** 2) <= max && ( sqrt(n ** 2 + m ** 2) == sqrt(n **2 + m ** 2).round )
          triplets << new(n, m, sqrt(n ** 2 + m ** 2).to_i)
        end
      end
    end
    options[:sum].nil? ? triplets : triplets.select { |triplet| triplet.sum == options[:sum] }
  end
end
