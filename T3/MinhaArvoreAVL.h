#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "ArvoreBinariaDeBusca.h"

/**
 * @brief Representa uma árvore AVL.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreAVL : public ArvoreBinariaDeBusca<T>
{
public:
    MinhaArvoreAVL():  raiz(nullptr), filhoEsquerda(nullptr), filhoDireita(nullptr), altura_(0) {}
    ~MinhaArvoreAVL() {
        while (raiz != nullptr) {
            Nodo<T>* proximo = raiz->filhoEsquerda;
            delete raiz;
            raiz = proximo;
        }
    }


    virtual bool vazia() const
    {
        if (this->raiz == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /**
     * @brief Retornar quantidade de chaves na arvore
     * @return Numero natural que representa a quantidade de chaves na arvore
     */
    int quantidadeRecursiva(Nodo<T> *nodo)const
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return 1 +
        this->quantidadeRecursiva(nodo->filhoEsquerda) + 
        this->quantidadeRecursiva(nodo->filhoDireita);
    }
    /**
     * @brief Retornar quantidade de chaves na arvore
     * @return Numero natural que representa a quantidade de chaves na arvore
     */
    virtual int quantidade()const
    {
        return this->quantidadeRecursiva(this->raiz);
    }

    /**
     * @brief Verifica se a arvore contem uma chave
     * @param chave chave a ser procurada na arvore
     * @return Verdade se a arvore contem a chave
     */
    
    /**
     * @brief Verifica se a arvore contem uma chave
     * @param chave chave a ser procurada na arvore
     * @return Verdade se a arvore contem a chave
     */
    virtual bool contem(T chave)const
    {
        return false;
    }
    
    
    /**
     * @brief Retorna a altura da (sub)arvore
     * @param chave chave que é raiz da (sub)arvore cuja altura queremos. 
     * @return Numero inteiro representando a altura da (subarvore). Se chave nao esta na arvore, retorna std::nullopt
     */
       
    virtual std::optional<int> altura(T chave) const
    {
        if (chave == nullptr)
            return 0;
        return node->altura_;
    }
        
    /**
     * @brief Insere uma chave na arvore
     * @param chave chave a ser inserida
     */        
    virtual void inserir(T chave)
    {        
    }

    /**
     * @brief Remove uma chave da arvore
     * @param chave chave a removida
     */        
    virtual void remover(T chave)
    {
       
    }

    /**
     * @brief Busca a chave do filho a esquerda de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a esquerda
     * @return Chave do filho a esquerda. Se chave nao esta na arvore, retorna std::nullopt
     */
    virtual std::optional<T> filhoEsquerdaDe(T chave) const
    {
        return std::nullopt;
    }

    /**
     * @brief Busca a chave do filho a direita de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a direita
     * @return Chave do filho a direita. Se chave nao esta na arvore, retorna nullptr
     */        
    virtual std::optional<T> filhoDireitaDe(T chave)const
    {
        return std::nullopt;
    }
    

    /**
     * @brief Lista chaves visitando a arvore em ordem
     * @return Lista encadeada contendo as chaves em ordem. 
     */
    virtual ListaEncadeadaAbstrata<T>* emOrdem() const
    {        
        return nullptr;
    }
    

    /**
     * @brief Lista chaves visitando a arvore em pre-ordem
     * @return Lista encadeada contendo as chaves em pre-ordem. 
     */
    virtual ListaEncadeadaAbstrata<T>* preOrdem() const
    {
        return nullptr;
    }
    

    /**
     * @brief Lista chaves visitando a arvore em pos-ordem
     * @return Lista encadeada contendo as chaves em pos ordem. 
     */
    virtual ListaEncadeadaAbstrata<T>* posOrdem() const
    {
        return nullptr;
    }
    private:
    Nodo<T> *raiz;
    Nodo<T> *filhoEsquerda;
    Nodo<T> *filhoDireita;
    std::size_t altura_;


    
};
#endif