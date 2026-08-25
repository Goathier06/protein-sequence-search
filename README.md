# Recherche de séquences protéiques - Smith-Waterman

Programme en C++ implémentant l'algorithme de **Smith-Waterman** pour rechercher, parmi une base de données de séquences protéiques, celles les plus similaires à une séquence de requête donnée (au format FASTA), au format des bases de données NCBI BLAST.

## Fonctionnalités

- Lecture de fichiers de requête au format FASTA
- Lecture des fichiers binaires d'une base de données au format NCBI BLAST (`.psq`, `.pin`, `.phr`)
- Lecture des matrices de score BLOSUM
- Alignement local optimal par programmation dynamique (algorithme de Smith-Waterman)
- Retour des séquences les plus proches de la requête, classées par score

## Stack technique

- C++
- Compilation via `Makefile` / `g++`
- Programmation dynamique pour l'alignement de séquences

## Compilation

```bash
make projet
```

## Utilisation

```bash
./projet <fichier_requête.fasta> <chemin_base_de_données> <fichier_blosum> <pénalité_ouverture_gap> <pénalité_extension_gap>
```

Des fichiers de requête d'exemple sont disponibles dans [`query_testprelim/`](query_testprelim) et [`query_testfinal/`](query_testfinal).

Les fichiers de base de données (NCBI BLAST) et les matrices BLOSUM ne sont pas inclus dans ce dépôt (voir [`database/README.md`](database/README.md) et [`blosum/README.md`](blosum/README.md)) — ils peuvent être téléchargés depuis UniProt/NCBI.

## Références

Ce projet s'appuie sur les travaux suivants :
- Smith, T.F. and Waterman, M.S. (1981). *Identification of common molecular subsequences.* Journal of Molecular Biology.
- Gotoh, O. (1982). *An improved algorithm for matching biological subsequences.* Journal of Molecular Biology.
- Rognes, T. (2011). *Faster Smith-Waterman database searches with inter-sequence SIMD parallelisation.* BMC Bioinformatics.
- Farrar, M.S. (2010). *NCBI BLAST Database Format.* NCBI.

## Rapport

Un rapport détaillant la conception et les choix d'implémentation est disponible : [`Rapport_INFO-H304_Groupe_9.pdf`](Rapport_INFO-H304_Groupe_9.pdf).

## Équipe

Projet réalisé en groupe dans le cadre du cours INFO-H304 (ULB) :
- Yasmina Bou Khaled
- Romain Dejean
- Gauthier Godeau
