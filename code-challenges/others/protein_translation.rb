class InvalidCodonError < Exception
end

class Translation
  CODON_LOOKUP = {'AUG' => 'Methionine',
                  'UUU' => 'Phenylalanine',
                  'UUC' => 'Phenylalanine',
                  'UUA' => 'Leucine',
                  'UUG' => 'Leucine',
                  'UCU' => 'Serine',
                  'UCC' => 'Serine',
                  'UCA' => 'Serine',
                  'UCG' => 'Serine',
                  'UAU' => 'Tyrosine',
                  'UAC' => 'Tyrosine',
                  'UGU' => 'Cysteine',
                  'UGC' => 'Cysteine',
                  'UGG' => 'Tryptophan',
                  'UAA' => 'STOP',
                  'UAG' => 'STOP',
                  'UGA' => 'STOP'
                  }

  def self.of_codon(codon)
    CODON_LOOKUP.fetch(codon) { fail InvalidCodonError }
  end

  def self.of_rna(strand)
    codons = strand.scan(/.{3}/)
    codons.each_with_object([]) do |codon, rna|
      return rna if of_codon(codon) == 'STOP'
      rna << of_codon(codon)
    end
  end
end