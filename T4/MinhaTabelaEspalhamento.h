#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente

template<typename T, std::size_t capac>
class MinhaTabelaEspalhamento:
    public TabelaEspalhamentoAbstrata<T, capac>
{
    public:
        MinhaTabelaEspalhamento() = default;
        ~MinhaTabelaEspalhamento() = default;
        /**
        * @brief Obtém a capacidade da tabela.
        * 
        * @return Um inteiro maior do que 0.
        */
        virtual std::size_t capacidade() const = 0;

        /**
        * @brief Insere um dado na tabela. Se a tabela já contiver o dado, ele não
        * é inserido novamente.
        * 
        * @param dado O dado a ser inserido.
        */
        virtual void inserir(T dado) = 0;
        /**
        * @brief Remove um dado da tabela. Se a tabela não contiver o dado, uma
        * exceção ExcecaoDadoInexistente é lançada.
        * 
        * @param dado O dado a ser removido.
        */
        virtual void remover(T dado) = 0;

        /**
        * @brief Verifica se \p dado está contido na tabela.
        * 
        * @param dado O dado sendo buscado.
        * @return true se o dado está contido na tabela; false caso contrário.
        */
        virtual bool contem(T dado) const = 0;

        /**
        * @brief Obtém a quantidade de dados contidos na árvore.
        * 
        * @return Um inteiro maior ou igual a 0.
        */
        virtual std::size_t quantidade() const = 0;
        protected:
            //Implemente as funções protegidas aqui
    
    private:
        /**
         * @brief Calcula a representação numérica de um tipo integral.
         * 
         * @tparam U O tipo integral.
         * @param integral Um valor integral.
         * @return Um inteiro calculado através de static_cast<std::size_t>(integral)
         */
        template<typename U>
        std::size_t codigoEspalhamento(U integral) const
        {
            //Implemente aqui. Dica use std::is_integral_v<U> para garantir que U é um tipo integral
        }
        
    
        /**
         * @brief Calcula a representação numérica de um string.
         * 
         * @param s um string.
         * @return Um inteiro calculado conforme s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1].
         */
        std::size_t codigoEspalhamento(std::string const& string) const
        {
            //Implemente aqui.
        }
    };

#endif
