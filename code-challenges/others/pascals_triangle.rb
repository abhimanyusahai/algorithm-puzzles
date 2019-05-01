class Triangle
  def initialize(total_rows)
    @total_rows = total_rows
  end

  def rows
    if @total_rows == 1
      result = [[1]]
    else
      result = Triangle.new(@total_rows - 1).rows
      last_row = (0..(@total_rows - 1)).to_a.map { |n| n == 0 ? 1 : result.last.fetch(n - 1) + result.last.fetch(n) {0} }
      result << last_row
    end
    result
  end
end
