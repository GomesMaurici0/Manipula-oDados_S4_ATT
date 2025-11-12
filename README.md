# Projeto TC - Votação de Trabalhos de Curso (IES)
> Projeto de Aplicação pratica de Manipulação de arquivos (.txt) - Manipulação / Projetar em C 
## Descrição 👾

Este projeto em **C** simula o sistema de votação para escolher o melhor Trabalho de Curso (TC) de uma instituição de ensino superior (IES).  

Ele permite:
- Ler informações de alunos, professores, TCs e comissão de votação a partir de arquivos.
- Registrar votos de eleitores válidos.
- Suspender e salvar votações parciais.
- Concluir a votação e gerar resultado final, identificando o(s) TC(s) vencedor(es).

O sistema também valida:
- CPF dos eleitores usando o algoritmo oficial.
- Existência de alunos e professores.
- Correspondência correta do aluno com o departamento do TC.

---

## Estrutura do Projeto 🏗️
```bash
Projeto_TC/
├─ include/ # Headers (.h)
├─ src/ # Código-fonte (.c)
├─ data/ # Arquivos de dados (.txt)
├─ output/ # Resultados gerados (.txt)
└─ README.md
```

---

## Como Compilar 🔥

1. Abra o terminal na pasta `Manipula-oDados_S4_ATT`.
2. Compile o projeto usando GCC, garantindo que o compilador encontre os headers:

```bash
gcc -Iinclude src/main.c src/arquivos.c src/validacoes.c src/votacao.c -o Projeto_TC.exe

```

3. Execute o programa:

```bash
./Projeto_TC.exe   # Linux/Mac
Projeto_TC.exe     # Windows
```

## Como Rodar ❓

1.  Ao iniciar, você verá o Menu 1:
    * Menu 1:
   ```bash
    * a) Iniciar nova votação
    * b) Continuar votação gravada
   ```

2. Se iniciar nova votação:
   * Menu 2: 
   ```bash
   * a) Entrar com voto
   * b) Suspender votação → salva em output/parcial.txt
   * c) Concluir votação → gera output/resultado.txt
   ```
3. Os votos são registrados por CPF de eleitores válidos e correspondência com os códigos dos TCs.

## Dependencias  🌀
* GCC ou qualquer compilador C compatível.
* Sistema operacional: Windows, Linux ou MacOS.

## Autores 🧑‍💻

<table>
  <tr>
    <td align="center">
      <b>Mauricio</b><br>
      <a href="https://www.instagram.com/maugms/">
        <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram">
      </a>
    </td>
    <td align="center">
      <b>Lucas</b><br>
      <a href="https://www.instagram.com/lczin_db/">
        <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram">
      </a>
    </td>
    <td align="center">
      <b>Matheus</b><br>
      <a href="https://www.instagram.com/_0mlopes/">
        <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram">
      </a>
    </td>
  </tr>
</table>
