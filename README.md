<h1 align="center">F.A.L.C.O.N</h1>
<h2 align="center">File Analysis & Lib for Checksums Obfuscation & Nuking </h2>

**Falcon** é uma ferramenta de linha de comando (CLI) desenvolvida em C com foco em segurança e integridade de arquivos. O objetivo principal é prover um conjunto de utilitários capazes de calcular e verificar hashes (como SHA-256), realizar operações seguras de remoção de arquivos (`shred`), e outras funcionalidades relacionadas à verificação e manipulação segura de dados.

> ⚠️ **Aviso:** Este projeto está em fase inicial de desenvolvimento. Muitas funcionalidades ainda estão sendo implementadas e podem não estar completas ou estáveis.

## Funcionalidades planejadas [TO-DO]

- [x] Cálculo de hash SHA-256 de arquivos
- [ ] Cálculo de MD5 de arquivos
- [ ] Salvar o hash de todos os arquivos no diretório atual
- [ ] Verificação de integridade com base em banco de dados de checksums
- [ ] Operação segura de destruição de arquivos (`shred`)
- [X] Interface de ajuda via `--help` e `-h`
- [ ] Outras opções CLI relacionadas à segurança de arquivos

## Compilação

Para compilar o Falcon, utilize um compilador C como `gcc` e utilize o `make` para fazerr a build:

```bash
git clone https://github.com/BrunoOfAstora/falcon/

cd falcon

make
