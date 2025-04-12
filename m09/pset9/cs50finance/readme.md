# CS50 Finance

CS50 Finance é um projeto desenvolvido como parte do curso CS50, que simula uma plataforma de negociação de ações. Ele permite que os usuários comprem e vendam ações, acompanhem seus portfólios e gerenciem suas finanças virtuais.

## Funcionalidades

- **Registro de Usuário**: Criação de contas com autenticação segura.
- **Compra e Venda de Ações**: Pesquisa de cotações em tempo real e execução de transações.
- **Histórico de Transações**: Registro detalhado de todas as operações realizadas.
- **Gerenciamento de Portfólio**: Visualização de ações possuídas e saldo disponível.
- **Cotações em Tempo Real**: Integração com APIs para obter preços atualizados.

## Tecnologias Utilizadas

- **Linguagem**: Python
- **Framework**: Flask
- **Banco de Dados**: SQLite
- **APIs**: IEX Cloud (para cotações de ações)
- **HTML/CSS/JavaScript**: Para a interface do usuário

## Como Executar

1. Clone o repositório:
     ```bash
     git clone <URL_DO_REPOSITORIO>
     ```
2. Instale as dependências:
     ```bash
     pip install -r requirements.txt
     ```
3. Configure a API Key do IEX Cloud no arquivo `.env`:
     ```
     API_KEY=your_api_key_here
     ```
4. Execute o servidor:
     ```bash
     flask run
     ```
5. Acesse o aplicativo em `http://127.0.0.1:5000`.

## Estrutura do Projeto

- `app.py`: Arquivo principal do aplicativo Flask.
- `templates/`: Contém os arquivos HTML.
- `static/`: Arquivos CSS e JavaScript.
- `helpers.py`: Funções auxiliares para validações e integração com APIs.
- `finance.db`: Banco de dados SQLite.

## Créditos

Este projeto foi desenvolvido como parte do curso [CS50's Introduction to Computer Science](https://cs50.harvard.edu/x/). 

## Licença

Este projeto é apenas para fins educacionais e segue as diretrizes do curso CS50.