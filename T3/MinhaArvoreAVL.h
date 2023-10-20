// MinhaArvoreAVL.hpp
#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "ArvoreBinariaDeBusca.h"
#include "MinhaListaEncadeada.h"

template <typename T>
class MinhaArvoreAVL : public ArvoreBinariaDeBusca<T>
{
public:
    MinhaArvoreAVL() : raiz(nullptr) {}
    ~MinhaArvoreAVL() = default;


    /**
     * @brief Verifica se a arvore esta vazia
     * @return Verdade se a arvore esta vazia.
     */
    virtual bool vazia() const
    {
        if (raiz == nullptr)
        {
            return true;
        }
        return false;
    }
    /**
    * @brief Retornar quantidade de chaves na arvore
    * @return Numero natural que representa a quantidade de chaves na arvore
    */
    virtual int quantidade() const
    {
        return quantidadeRecursiva(raiz);
    }
    /**
    * @brief Verifica se a arvore contem uma chave
    * @param chave chave a ser procurada na arvore
    * @return Verdade se a arvore contem a chave
    */
    virtual bool contem(T chave) const
    {
        return contemRecursivo(raiz, chave);
    }
    /**
    * @brief Retorna a altura da (sub)arvore
    * @param chave chave que é raiz da (sub)arvore cuja altura queremos. 
    * @return Numero inteiro representando a altura da (subarvore). Se chave nao esta na arvore, retorna std::nullopt
    */
    virtual std::optional<int> altura(T chave) const
    {
        return alturaRecursiva(raiz, chave);
    }

    /**
    * @brief Insere uma chave na arvore
    * @param chave chave a ser inserida
    */ 
    virtual void inserir(T chave)
    {
        raiz = inserirRecursivo(raiz, chave);
    }
    /**
    * @brief Remove uma chave da arvore
    * @param chave chave a removida
    */
    virtual void remover(T chave)
    {
        raiz = removerRecursivo(raiz, chave);
    }

    /**
    * @brief Busca a chave do filho a esquerda de uma (sub)arvore
    * @param chave chave da arvore que eh pai do filho a esquerda
    * @return Chave do filho a esquerda. Se chave nao esta na arvore, retorna std::nullopt
    */
    virtual std::optional<T> filhoEsquerdaDe(T chave) const
    {
        Nodo<T>* nodo = buscarNodo(raiz, chave);
        if (nodo && nodo->filhoEsquerda)
        {
            return nodo->filhoEsquerda->chave;
        }
        return std::nullopt;
    }
    /**
    * @brief Busca a chave do filho a direita de uma (sub)arvore
    * @param chave chave da arvore que eh pai do filho a direita
    * @return Chave do filho a direita. Se chave nao esta na arvore, retorna nullptr
    */ 
    virtual std::optional<T> filhoDireitaDe(T chave) const
    {
        Nodo<T>* nodo = buscarNodo(raiz, chave);
        if (nodo && nodo->filhoDireita)
        {
            return nodo->filhoDireita->chave;
        }
        return std::nullopt;
    }

    /**
    * @brief Lista chaves visitando a arvore em ordem
    * @return Lista encadeada contendo as chaves em ordem. 
    */
    virtual MinhaListaEncadeada<T>* emOrdem() const
    {
        MinhaListaEncadeada<T>* lista = new MinhaListaEncadeada<T>();
        emOrdemRecursivo(raiz, lista);
        return lista;
    }
    /**
    * @brief Lista chaves visitando a arvore em pre-ordem
    * @return Lista encadeada contendo as chaves em pre-ordem. 
    */
    virtual MinhaListaEncadeada<T>* preOrdem() const
    {
        MinhaListaEncadeada<T>* lista = new MinhaListaEncadeada<T>();
        preOrdemRecursivo(raiz, lista);
        return lista;
    }
    /**
    * @brief Lista chaves visitando a arvore em pos-ordem
    * @return Lista encadeada contendo as chaves em pos ordem. 
    */
    virtual MinhaListaEncadeada<T>* posOrdem() const
    {
        MinhaListaEncadeada<T>* lista = new MinhaListaEncadeada<T>();
        posOrdemRecursivo(raiz, lista);
        return lista;
    }


    //Baseado no exemplo que o professor fez em aula quantidadeRecursiva
    int quantidadeRecursiva(Nodo<T>* nodo) const
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return 1 + quantidadeRecursiva(nodo->filhoEsquerda) + quantidadeRecursiva(nodo->filhoDireita);
    }

    //Contem recursivo 
    bool contemRecursivo(Nodo<T>* nodo, T chave) const
    {
        if (nodo == nullptr)
        {
            return false;
        }
        if (nodo->chave == chave)
        {
            return true;
        }
        if (chave < nodo->chave)
        {
            return contemRecursivo(nodo->filhoEsquerda, chave);
        }
        else
        {
            return contemRecursivo(nodo->filhoDireita, chave);
        }
    }
    //Altura recursiva
    std::optional<int> alturaRecursiva(Nodo<T>* nodo, T chave) const
    {
        Nodo<T>* objetivo = buscarNodo(nodo, chave);
        if (objetivo)
        {
            return objetivo->altura;
        }
        return std::nullopt;
    }

    //Funcao adicional para buscar um nodo especifico
    Nodo<T>* buscarNodo(Nodo<T>* nodo, T chave) const
    {
        if (nodo == nullptr)
        {
            return nullptr;
        }
        if (nodo->chave == chave)
        {
            return nodo;
        }
        if (chave < nodo->chave)
        {
            return buscarNodo(nodo->filhoEsquerda, chave);
        }
        else
        {
            return buscarNodo(nodo->filhoDireita, chave);
        }
    }

    //Funcao para inserir recursivamente
    Nodo<T>* inserirRecursivo(Nodo<T>* nodo, T chave)
    {
        if (nodo == nullptr)
        {
            return new Nodo<T>{chave};
        }
        if (chave < nodo->chave)
        {
            nodo->filhoEsquerda = inserirRecursivo(nodo->filhoEsquerda, chave);
        }
        else if (chave > nodo->chave)
        {
            nodo->filhoDireita = inserirRecursivo(nodo->filhoDireita, chave);
        }
        else
        {
            return nodo; // Duplicou a chave
        }

        // atualiza a altura do nodo pai
        nodo->altura = 1 + std::max(alturaNodo(nodo->filhoEsquerda), alturaNodo(nodo->filhoDireita));

        int balanca = balanceado(nodo);

        // esquerda esta mais pesada
        if (balanca > 1)
        {
            if (chave < nodo->filhoEsquerda->chave)
            {
                return rotacaoDireita(nodo);
            }
            else
            {
                nodo->filhoEsquerda = rotacaoEsquerda(nodo->filhoEsquerda);
                return rotacaoDireita(nodo);
            }
        }

        // Direita esta mais pesada 
        if (balanca < -1)
        {
            if (chave > nodo->filhoDireita->chave)
            {
                return rotacaoEsquerda(nodo);
            }
            else
            {
                nodo->filhoDireita = rotacaoDireita(nodo->filhoDireita);
                return rotacaoEsquerda(nodo);
            }
        }

        return nodo;
    }
    //Funcao para remover recursivamente
    Nodo<T>* removerRecursivo(Nodo<T>* nodo, T chave)
    {
        if (nodo == nullptr)
        {
            return nodo;
        }

        if (chave < nodo->chave)
        {
            nodo->filhoEsquerda = removerRecursivo(nodo->filhoEsquerda, chave);
        }
        else if (chave > nodo->chave)
        {
            nodo->filhoDireita = removerRecursivo(nodo->filhoDireita, chave);
        }
        else
        {
            if (nodo->filhoEsquerda == nullptr || nodo->filhoDireita == nullptr)
            {
                Nodo<T>* temp = (nodo->filhoEsquerda) ? nodo->filhoEsquerda : nodo->filhoDireita;

                if (temp == nullptr)
                {
                    temp = nodo;
                    nodo = nullptr;
                }
                else
                {
                    *nodo = *temp;
                }

                delete temp;
            }
            else
            {
                Nodo<T>* temp = menorNodo(nodo->filhoDireita);
                nodo->chave = temp->chave;
                nodo->filhoDireita = removerRecursivo(nodo->filhoDireita, temp->chave);
            }
        }

        if (nodo == nullptr)
        {
            return nodo;
        }

        // Atualiza a altura do nodo pai
        nodo->altura = 1 + std::max(alturaNodo(nodo->filhoEsquerda), alturaNodo(nodo->filhoDireita));

        int balanca = balanceado(nodo);

        // ESquerda mais pesada 
        if (balanca > 1)
        {
            if (balanceado(nodo->filhoEsquerda) >= 0)
            {
                return rotacaoDireita(nodo);
            }
            else
            {
                nodo->filhoEsquerda = rotacaoEsquerda(nodo->filhoEsquerda);
                return rotacaoDireita(nodo);
            }
        }

        // DIreita mais pesadaa
        if (balanca < -1)
        {
            if (balanceado(nodo->filhoDireita) <= 0)
            {
                return rotacaoEsquerda(nodo);
            }
            else
            {
                nodo->filhoDireita = rotacaoDireita(nodo->filhoDireita);
                return rotacaoEsquerda(nodo);
            }
        }

        return nodo;
    }

    //Funcao auxiliar para pegar a altura de um nodo
    int alturaNodo(Nodo<T>* nodo) const
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return nodo->altura;
    }

    //Funcao adicional para pegar o balanceamento de um nodo
    int balanceado(Nodo<T>* nodo) const
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return alturaNodo(nodo->filhoEsquerda) - alturaNodo(nodo->filhoDireita);
    }

    Nodo<T>* menorNodo(Nodo<T>* nodo)
    {
        Nodo<T>* atual = nodo;
        while (atual->filhoEsquerda != nullptr)
        {
            atual = atual->filhoEsquerda;
        }
        return atual;
    }

    Nodo<T>* rotacaoEsquerda(Nodo<T>* nodo)
    {
        Nodo<T>* novoRaiz = nodo->filhoDireita;
        Nodo<T>* tmp = novoRaiz->filhoEsquerda;
        novoRaiz->filhoEsquerda = nodo;
        nodo->filhoDireita = tmp;

        nodo->altura = 1 + std::max(alturaNodo(nodo->filhoEsquerda), alturaNodo(nodo->filhoDireita));
        novoRaiz->altura = 1 + std::max(alturaNodo(novoRaiz->filhoEsquerda), alturaNodo(novoRaiz->filhoDireita));

        return novoRaiz;
    }

    Nodo<T>* rotacaoDireita(Nodo<T>* nodo)
    {
        Nodo<T>* novaRaiz = nodo->filhoEsquerda;
        Nodo<T>* tmp = novaRaiz->filhoDireita;
        novaRaiz->filhoDireita = nodo;
        nodo->filhoEsquerda = tmp;

        nodo->altura = 1 + std::max(alturaNodo(nodo->filhoEsquerda), alturaNodo(nodo->filhoDireita));
        novaRaiz->altura = 1 + std::max(alturaNodo(novaRaiz->filhoEsquerda), alturaNodo(novaRaiz->filhoDireita));

        return novaRaiz;
    }

    void emOrdemRecursivo(Nodo<T>* nodo, MinhaListaEncadeada<T>* lista) const
    {
        if (nodo != nullptr)
        {
            emOrdemRecursivo(nodo->filhoEsquerda, lista);
            lista->inserirNoFim(nodo->chave);
            emOrdemRecursivo(nodo->filhoDireita, lista);
        }
    }

    void preOrdemRecursivo(Nodo<T>* nodo, MinhaListaEncadeada<T>* lista) const
    {
        if (nodo != nullptr)
        {
            lista->inserirNoFim(nodo->chave);
            preOrdemRecursivo(nodo->filhoEsquerda, lista);
            preOrdemRecursivo(nodo->filhoDireita, lista);
        }
    }

    void posOrdemRecursivo(Nodo<T>* nodo, MinhaListaEncadeada<T>* lista) const
    {
        if (nodo != nullptr)
        {
            posOrdemRecursivo(nodo->filhoEsquerda, lista);
            posOrdemRecursivo(nodo->filhoDireita, lista);
            lista->inserirNoFim(nodo->chave);
        }
    }
private:
    Nodo<T>* raiz;
};
#endif
