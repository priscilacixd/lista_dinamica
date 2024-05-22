# Lista Dinâmica de Produtos (C)

Este projeto implementa uma lista dinâmica de produtos em C, permitindo inserir, remover e visualizar produtos.

## Descrição

O código implementa uma lista dinâmica encadeada, utilizando uma estrutura `cadastro` para armazenar as informações de cada produto (nome e código) e uma estrutura `no` para representar cada nó da lista.

## Funcionalidades

* **Inserir:** Permite inserir um novo produto na lista, solicitando o nome e código do produto ao usuário.
* **Remover:** Permite remover um produto da lista, utilizando como critério o código ou o nome do produto.
* **Visualizar:** Exibe os produtos presentes na lista.
* **Remover Pilha (LIFO):** Remove o último produto adicionado à lista.
* **Remover Fila (FIFO):** Remove o primeiro produto adicionado à lista.

## Instruções de uso

1. Compile o código fonte com um compilador C (ex: GCC).
2. Execute o programa.
3. Utilize as opções do menu para inserir, remover ou visualizar produtos.

## Observações

* O código possui um menu interativo que facilita a navegação entre as funcionalidades.
* A remoção por código ou nome é feita buscando o produto correspondente na lista.
* As funções de remoção de pilha e fila implementam as estruturas de dados LIFO e FIFO, respectivamente.

## Próximos passos

* Implementar a pesquisa de produtos por nome ou código.
* Adicionar a funcionalidade de edição de produtos.

## Considerações

* O código é um exemplo básico de implementação de lista dinâmica em C, com funcionalidades básicas.
* O código pode ser expandido com novas funcionalidades e modificado para atender a requisitos específicos.
* O código foi testado em ambiente Windows, utilizando o compilador GCC.

## Licença

Este projeto está licenciado sob a licença MIT - consulte o arquivo LICENSE para obter mais detalhes.
