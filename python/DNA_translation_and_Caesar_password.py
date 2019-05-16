#!/usr/bin/env python
# coding: utf-8

# In[2]:


import string

def read_seq(inputfile):
    """Reads and returns the input sequence with special characters removed."""
    # your code here
    file = open(inputfile,"r")
    seq = file.read()
    seq = seq.replace("\n","")
    seq = seq.replace("\r","")
    return seq

def translate(seq):
    """Translate a string containing a nucleotide sequence
    into a string containing the corresponding sequence of
    amino acids. Nucleotides are translated in triplets using
    the table dictionary; each amino acid is encoded with
    a string of length 1."""
    table = {
    'ATA':'I', 'ATC':'I', 'ATT':'I', 'ATG':'M',
    'ACA':'T', 'ACC':'T', 'ACG':'T', 'ACT':'T',
    'AAC':'N', 'AAT':'N', 'AAA':'K', 'AAG':'K',
    'AGC':'S', 'AGT':'S', 'AGA':'R', 'AGG':'R',
    'CTA':'L', 'CTC':'L', 'CTG':'L', 'CTT':'L',
    'CCA':'P', 'CCC':'P', 'CCG':'P', 'CCT':'P',
    'CAC':'H', 'CAT':'H', 'CAA':'Q', 'CAG':'Q',
    'CGA':'R', 'CGC':'R', 'CGG':'R', 'CGT':'R',
    'GTA':'V', 'GTC':'V', 'GTG':'V', 'GTT':'V',
    'GCA':'A', 'GCC':'A', 'GCG':'A', 'GCT':'A',
    'GAC':'D', 'GAT':'D', 'GAA':'E', 'GAG':'E',
    'GGA':'G', 'GGC':'G', 'GGG':'G', 'GGT':'G',
    'TCA':'S', 'TCC':'S', 'TCG':'S', 'TCT':'S',
    'TTC':'F', 'TTT':'F', 'TTA':'L', 'TTG':'L',
    'TAC':'Y', 'TAT':'Y', 'TAA':'_', 'TAG':'_',
    'TGC':'C', 'TGT':'C', 'TGA':'_', 'TGG':'W'
    }
    # check that the sequence length is divisible by 3
    # loop over the sequence, extract a single codon
    # loop up the codon and store the result
    protein = ""        
    # your code here
    for i in range(0,len(seq),3):
        protein += table[seq[i:i+3]]
    return protein


def encode_dict(encryption_key):
    # your code is here
    alphabet = string.ascii_lowercase + " "

    encoding = {}
    j = encryption_key%27
    for item in alphabet:
        encoding[item] = j%27
        j += 1
    return encoding

def caesar(message,encryption_key):
    # return the encoded message as a single string!
    encoded_message = ''
    # use the function in Step 2 to get the encoding dictionary
    encoding = encode_dict(encryption_key)
    # your code is here
    # for each letter in message, get the encoded letter
    alphabet = string.ascii_lowercase + " "
    letters = {}
    j = 0
    for item in alphabet:
        letters[j] = item
        j += 1
    
    for item in message:
         encoded_message += letters[encoding[item]]
        
    return encoded_message    

#加密
message = "hi my name is caesar"
encryption_key = 3
encoded_message = caesar(message,encryption_key)
print(encoded_message)

#解密
decoded_message = caesar(encoded_message,-3)
print(decoded_message)


# In[ ]:




