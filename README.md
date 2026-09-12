# Protein Sequence Search - Smith-Waterman

C++ program implementing the **Smith-Waterman** algorithm to search, within a protein sequence database, for the sequences most similar to a given query sequence (in FASTA format), using the NCBI BLAST database format.

## Features

- Reading query files in FASTA format
- Reading binary database files in NCBI BLAST format (`.psq`, `.pin`, `.phr`)
- Reading BLOSUM scoring matrices
- Optimal local alignment using dynamic programming (Smith-Waterman algorithm)
- Returning the sequences closest to the query, ranked by score

## Technical Stack

- C++
- Compilation via `Makefile` / `g++`
- Dynamic programming for sequence alignment

## Compilation

```bash
make projet
```

## Usage

```bash
./projet <query_file.fasta> <database_path> <blosum_file> <gap_open_penalty> <gap_extension_penalty>
```

Example query files are available in [`query_testprelim/`](query_testprelim) and [`query_testfinal/`](query_testfinal).

The NCBI BLAST database files and BLOSUM matrices are not included in this repository (see [`database/README.md`](database/README.md) and [`blosum/README.md`](blosum/README.md)) — they can be downloaded from UniProt/NCBI.

## References

This project is based on the following works:
- Smith, T.F. and Waterman, M.S. (1981). *Identification of common molecular subsequences.* Journal of Molecular Biology.
- Gotoh, O. (1982). *An improved algorithm for matching biological subsequences.* Journal of Molecular Biology.
- Rognes, T. (2011). *Faster Smith-Waterman database searches with inter-sequence SIMD parallelisation.* BMC Bioinformatics.
- Farrar, M.S. (2010). *NCBI BLAST Database Format.* NCBI.

## Report

A report detailing the design and implementation choices is available: [`Rapport_INFO-H304_Groupe_9.pdf`](Rapport_INFO-H304_Groupe_9.pdf).

## Team

Group project completed as part of the INFO-H304 course (ULB):
- Yasmina Bou Khaled
- Romain Dejean
- Gauthier Godeau
