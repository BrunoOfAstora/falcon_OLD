<h1 align="center">F.A.L.C.O.N🦅</h1>
<h2 align="center"> File Analysis & Lib for Checksums Obfuscation & Nuking </h2>

**Falcon** é uma ferramenta de linha de comando (CLI) escrita em **C**, focada em **segurança**, **integridade de arquivos** e **operações de manipulação segura de dados**.

O principal objetivo é fornecer um conjunto de utilitários para :

- Calcular e verificar hashes (ex: **SHA-256**, **SHA-384**, **MD5**)
- Realizar operações seguras de remoção de arquivos (**shred**, futuramente)
- Detectar duplicatas
- Trabalhar com banco de dados de checksums

> ⚠️ **Aviso:** Este projeto está em fase inicial de desenvolvimento. Algumas funcionalidades ainda estão incompletas ou instáveis.

## 📌 Como Usar

Após compilar o Falcon, você poderá executar os seguintes comandos diretamente no terminal:

| Comando                          | Descrição                                        |
|----------------------------------|--------------------------------------------------|
| `falcon save .`                  | Salva o hash de todos os arquivos no diretório atual |
| `falcon md5 <arquivo>`           | Calcula o hash **MD5** de um arquivo             |
| `falcon sha256 <arquivo>`        | Calcula o hash **SHA-256**                      |
| `falcon sha384 <arquivo>`        | Calcula o hash **SHA-384**                      |
| `falcon rmdup`                   | Remove arquivos duplicados no diretório atual   |
| `falcon verify`                  | Verifica integridade com base nos hashes salvos (Parcial) |
| `falcon --help` ou `falcon -h`   | Exibe o menu de ajuda                           |

## 🛠️ Compilação

Requisitos: **Linux** + **GCC**

```bash
git clone https://github.com/BrunoOfAstora/falcon.git
cd falcon
make
```

O binário `falcon` será gerado na pasta raiz do projeto.

## ✅ Funcionalidades Concluídas

- ✅ Cálculo de hash **MD5**
- ✅ Cálculo de hash **SHA-256**
- ✅ Cálculo de hash **SHA-384**
- ✅ Remoção de duplicatas no diretório atual
- ✅ Verificação parcial de integridade (compare hashes salvos)
- ✅ Interface de ajuda via `--help` e `-h`

## 🚧 Funcionalidades Planejadas (To-Do)

- [ ] Finalizar a verificação completa de integridade
- [ ] Opção de **shred**
- [ ] Exportar hashes de diretórios inteiros em formato padrão
- [ ] Suporte a outros algoritmos de hash (ex: SHA-512)
- [ ] Melhorias no parser de argumentos CLI
- [ ] Outros...
      
      
