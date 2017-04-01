class Anagram
  def initialize(word)
    @word = word
  end

  def match(input_list)
    input_list.select { |candidate| candidate.downcase != @word.downcase &&
                                    candidate.downcase.chars.sort == @word.downcase.chars.sort }
  end
end

