#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H
// codigo para concluir os testes do arquivo main.cpp


#include <cstddef>
// std::size_t

#include "Elemento.h"
// Elemento
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"
// ExcecaoDadoInexistente
// ExcecaoListaEncadeadaVazia
// ExcecaoNaoImplementado
// ExcecaoPosicaoInvalida

/**
 * @brief Uma lista encadeada de dados.
 * 
 * @tparam T O tipo dos dados armazenados na lista.
 */
template<typename T>
//classe de lista encadeada
class MinhaListaEncadeada: public ListaEncadeadaAbstrata<T>
{
public:
    //construtor e destrutor da classe
    MinhaListaEncadeada() : primeiro(nullptr), ultimo(nullptr), tamanho_(0) {}
    ~MinhaListaEncadeada() {
        while (primeiro != nullptr) {
            Elemento<T>* proximo = primeiro->proximo;
            delete primeiro;
            primeiro = proximo;
        }
    }
    //metodos da classe
    // calcula e retorna o tamanho da lista
    virtual std::size_t tamanho() const{
        return tamanho_;
    }
    /**
     * @brief Indica se há algum item na lista ou não.
     * 
     * @return false se houver algum item na lista; true caso contrário.
     */
    virtual bool vazia() const{
        if (tamanho_ == 0) {
            return true;
        }
        return false;
    }

    /**
     * @brief Obtém a posição de um item na lista. Lança
     * ExcecaoListaEncadeadaVazia caso a lista esteja vazia ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item cuja posição deseja-se obter.
     * @return Um inteiro na faixa [0, tamanho); se houver mais que um mesmo
     * item na lista, a posição da primeira ocorrência.
     */
    virtual std::size_t posicao(T dado) const{
        size_t posicao = 0;
        Elemento<T>* atual = primeiro;
        while (atual != nullptr) {
            if (atual->dado == dado) {
                return posicao;
            }
            atual = atual->proximo;
            posicao++;
        }
        if (posicao == 0) {
            throw ExcecaoListaEncadeadaVazia();
        }else{
            throw ExcecaoDadoInexistente();
        }
    return posicao;
    }
    /**
     * @brief Indica se um dado item está contido na lista ou não.
     * 
     * @param dado O item sendo buscado.
     * @return true se o item está contido na lista; false caso contrário.
     */
    virtual bool contem(T dado) const {
        Elemento<T>* atual = primeiro;
        while (atual != nullptr) {
            if (atual->dado == dado) {
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }

    /**
     * @brief Insere um item no início da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoInicio(T dado) {

        Elemento<T>* novo = new Elemento<T>(dado, primeiro);
        primeiro = novo;
        if (tamanho_ == 0) {
            ultimo = novo;
        }
        tamanho_++;
        
    }
    /**
     * @brief Insere um item em uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa
     * [0, tamanho].
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho]. Ao se inserir em
     * uma posição já ocupada, a posição do item que já estava naquela posição
     * será posicao + 1; inserir-se na posicao tamanho significa inserir-se no
     * fim da lista.
     * @param dado O item sendo inserido.
     */
    virtual void inserir(std::size_t posicao, T dado) {
        if (posicao > tamanho_) {
            throw ExcecaoPosicaoInvalida();
        }
        if (posicao == 0) {
            inserirNoInicio(dado);
        }else if (posicao == tamanho_) {
            inserirNoFim(dado);
        }else{
            Elemento<T>* atual = primeiro;
            for (size_t i = 0; i < posicao - 1; i++) {
                atual = atual->proximo;
            }
            Elemento<T>* novo = new Elemento<T>(dado, atual->proximo);
            atual->proximo = novo;
            tamanho_++;
        }
       
    }
    /**
     * @brief Insere um item no fim da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoFim(T dado) {
        Elemento<T>* novo = new Elemento<T>(dado, nullptr);
        if (tamanho_ == 0) {
            primeiro = novo;
        }else{
            ultimo->proximo = novo;
        }
        ultimo = novo;
        tamanho_++;
     
    }

    /**
     * @brief Remove o primeiro item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoInicio() { 
        if (tamanho_ == 0) {
            throw ExcecaoListaEncadeadaVazia();
        }
        Elemento<T>* removido = primeiro;
        T dado = removido->dado;
        primeiro = primeiro->proximo;
        delete removido;
        tamanho_--;
        return dado;   

    }

    /**
     * @brief Remove um item de uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa [0, tamanho).
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho).
     * @return O item removido.
     */
    virtual T removerDe(std::size_t posicao){
        if (posicao >= tamanho_) {
            throw ExcecaoPosicaoInvalida();
        }
        if (posicao == 0) {
            return removerDoInicio();
        }else if (posicao == tamanho_ - 1) {
            return removerDoFim();
        }else{
            Elemento<T>* atual = primeiro;
            for (size_t i = 0; i < posicao - 1; i++) {
                atual = atual->proximo;
            }
            Elemento<T>* removido = atual->proximo;
            T dado = removido->dado;
            atual->proximo = removido->proximo;
            delete removido;
            tamanho_--;
            return dado;
        }
    }
    /**
     * @brief Remove o último item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoFim(){
        if (tamanho_ == 0) {
            throw ExcecaoListaEncadeadaVazia();
        }
        Elemento<T>* atual = primeiro;
        Elemento<T>* anterior = nullptr;
        while (atual->proximo != nullptr) {
            anterior = atual;
            atual = atual->proximo;
        }
        T dado = atual->dado;
        if (anterior == nullptr) {
            primeiro = nullptr;
        }else{
            anterior->proximo = nullptr;
        }
        ultimo = anterior;
        delete atual;
        tamanho_--;
        return dado;
        
        
    }


    /**
     * @brief Remove um item específico da lista. Lança
     * ExcecaoListaEncadeadaVazia caso não haja nenhum item na lista ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item a ser removido. Se houver mais que um item com
     * o mesmo valor, remove a primeira ocorrência.
     */
    virtual void remover(T dado){
        if (tamanho_ == 0) {
            throw ExcecaoListaEncadeadaVazia();
        }
        Elemento<T>* atual = primeiro;
        Elemento<T>* anterior = nullptr;
        while (atual != nullptr) {
            if (atual->dado == dado) {
                if (anterior == nullptr) {
                    removerDoInicio();
                }else{
                    anterior->proximo = atual->proximo;
                    delete atual;
                    tamanho_--;
                }
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }
        throw ExcecaoDadoInexistente();
    }
    private:

    Elemento<T>* primeiro;
    Elemento<T>* ultimo;
    std::size_t tamanho_;
};

#endif