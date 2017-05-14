
## Esquece os ramos
Num trabalho inidividual onde tudo é bem coordenado e a equipa são 2 ou 3 pessoas, o uso de branches individuais não faz muito sentido.
> **Em que situações se de usar branches ?**<br>
Os branches devem ser utilizados quando se está a fazer uma funcionalidade nova que pode estragar tudo e por isso cria-se um branch e trabalha-se nele.
<br>***Exemplo :***<br>
O João e o André estão a fazer uma aplicação para Android. A certa altura o João acha que seria uma boa ideia poder fazer uma ligação á internet para descarregar determinadas coisas para a sua aplicação, que terão efeito mais tarde. O André aceita, mas como não sabem se aquilo vai correr bem, ao invés de fazer asneiras, o João passa a trabalhar num novo branch. Se no final tudo estiver funcional, então efetua-se um merge do branch experimental do João sobre aquele em que ambos trabalhavam anteriormente. Se correr mal, apaga-se tudo!<br>
(imagem aqui)

Por isso mesmo vamos assumir que duas pessoas estão a trabalhar sobre o branch master.
As duas pessoas são denominadas respetivamente por *user1* e *user2*. O *user1* vai criar o repositório, adicionar o *user2* como colaborador e de seguida vai adicionar algum código. Daqui em diante os dois irão trabalhar normalmente.
> **Nota importante**<br>
O código a ser utilizado está na pasta *passos* e dentro tem *user1* e *user2* que corresponde aos utilizadores. Para cada utilizador existem varias pastas com os nomes *commit1*, *commit2*, etc, que corresponde ao código a ser enviado em cada commit. Faça-se uso desta pasta e do código no interior da mesma.

### "Passito a passito"
Os comandos a ser usados são :<br>
`$ git add`<br>
`$ git commit`<br>
`$ git fetch`<br>
`$ git rebase`<br>
`$ git push`<br>

Cada utilizador irá recorrer a diferentes comandos em diferentes instantes. Vejamos um possivel fluxo:
* *user1*
    * cria repositório
    * adiciona user2 aos colaboradores
    * adiciona código da pasta init
    * carregar código para o servidor remoto
* *user2*
    * colona o repositório
    * adiciona código do commit1
    * carregar código para o servidor remoto
* *user1*
    * adicionar código do commit1
    * carregar código para o servidor remoto

> **Para adicionar código**<br>
Os passos para adicionar código são os apresentados acima, na ordem apresentada acima.
Se ocorrerem conflitos durante um *rebase* então é necessários resolver esses conflitos, adicionar os ficheiros com `git add .` e terminar o *rebase* com `git rebase --continue`.

* *user2*
    * adicionar código do commit2
    * salvar temporariamente as alteraçoes e descarregar o código atualizado do servidor remoto
    * aplicar alterações salvas temporariamente
    * carregar código para o servidor remoto

> **Temporariamente**<br>
Para guardar as alterações temporariamente utiliza-se o comando `git stash` e para aplica-las novamente utiliza-se `git stash pop`. Uma vez que as alterações são salvas, é retomado o código do ultimo commit e pode então efetuar-se quantas alterações se pretenda. No final aplicam-se essas alterações salvas sobre o código atual. (Podem ocorrer conflitos).

* *user1*
    * adicionar código do commit2
    * carregar código para o servidor remoto
    * adicionar código do commit2b
    * carregar código para o servidor remoto
    * adicionar código do commit3
    * carregar código para o servidor remoto
* *user2*
    * adicionar código do commit3
    * carregar código para o servidor remoto
