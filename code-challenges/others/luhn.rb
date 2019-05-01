class Luhn
  def initialize(input_num)
    @input_num = input_num
  end

  def addends
    addends = @input_num.to_s.split("").reverse.each_with_index.map do |digit, idx|
                if idx.even?
                  digit.to_i
                else
                  digit.to_i * 2 >= 10 ? (digit.to_i * 2) - 9 : digit.to_i * 2
                end
              end
    addends.reverse
  end

  def checksum
    addends.reduce(:+)
  end

  def valid?
    checksum % 10 == 0
  end

  def self.create(input_num)
    luhn = Luhn.new(input_num * 10)
    luhn.valid? ? input_num * 10 : input_num * 10 + (10 - luhn.checksum % 10)
  end
end
