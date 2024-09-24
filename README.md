## Задача
Создать сеть абстрактных узлов и метод ее обновления, работающий по следующим принципам:

### Действия узлов
Каждый узел сети может выполнить одно из следующих действий:

1. **Создать событие**:
   - Узел сети может создать событие, содержащее случайное число.

2. **Подписаться на события**:
   - Узел может подписаться на события любого соседа любого своего соседа, кроме самого себя.

3. **Отписаться от соседей**:
   - Узел может отписаться от любого своего соседа.

4. **Создать новый узел**:
   - Узел может создать новый узел и подписаться на него. Новый узел не участвует в текущем обновлении.

5. **Не выполнять действия**:
   - Узел может не выполнять никаких действий.

### Обработчики событий
При подписке узел назначает один из следующих обработчиков события:
- **Сумма событий**:
  - Вывод в консоль: `"имя-отправителя -> имя-получателя: S = сумма-всех-чисел-полученных-от-этого-отправителя"`
  
- **Количество событий**:
  - Вывод в консоль: `"имя-отправителя -> имя-получателя: N = число-событий-полученных-от-этого-отправителя"`

### Условия завершения
- Если узел лишается всех соседей, он уничтожается в конце процедуры обновления сети.
- Узлы считаются соседями, если один из них подписан на события другого. 
- В случае невозможности выполнения выбранного узлом действия, попыток выполнить другое действие не осуществляется.

### Обновление сети
- Обновление узлов сети должно происходить синхронно:
  - Изменения, созданные в процессе обновления уже обработанными узлами, не должны учитываться узлами, которые еще не обработаны.

### Параметры
- Вероятность каждого события задается вручную при запуске программы.
- Стартовая сеть создается случайным образом с произвольными параметрами, которые могут задаваться с клавиатуры или генерироваться случайно.

### Завершение симуляции
Программа должна продолжать симуляцию до вырождения сети или до явной остановки симуляции.
