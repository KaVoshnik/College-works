## 1. Описание структур (Series, Dataframe)

### 1.1 Series

* **Определение:**  `Series` - одномерный объект библиотеки pandas, похожий на массив, но с дополнительными возможностями.
* **Структура:** Состоит из двух связанных массивов:
    * Основной массив: хранит данные любого типа из NumPy.
    * Массив `index`: хранит метки для каждого элемента данных.
* **Пример:**
    ```python
    import pandas as pd
    s = pd.Series([12, -4, 7, 9])
    print(s)
    ```
    **Вывод:**
    ```
    0    12
    1    -4
    2     7
    3     9
    dtype: int64
    ```
* **Особенности:**
    * Значения из исходного объекта Series не копируются, а передаются по ссылке.
    * Изменения в исходном объекте отражаются в Series.
    * Поддерживает операции, применимые к массивам NumPy.
    * Может содержать дубликаты значений.

### 1.2 DataFrame

* **Определение:** `DataFrame` - табличная структура данных, подобная таблице Excel, представляющая собой набор многомерных `Series`.
* **Структура:** 
    * Состоит из упорядоченной коллекции колонок.
    * Каждая колонка может содержать значения разных типов (числовые, строковые, булевые и т.д.).
* **Пример:**
    ```python
    import pandas as pd
    data = {'color': ['blue', 'green', 'yellow', 'red', 'white'],
            'object': ['ball', 'pen', 'pencil', 'paper', 'mug'],
            'price': [1.2, 1.0, 0.6, 0.9, 1.7]}
    frame = pd.DataFrame(data)
    print(frame)
    ```
    **Вывод:**
    ```
       color  object  price
    0   blue    ball    1.2
    1  green     pen    1.0
    2  yellow  pencil    0.6
    3    red   paper    0.9
    4  white     mug    1.7
    ```
* **Особенности:**
    *  Автоматическое присвоение числовых индексов, если метки не заданы.
    *  Возможность задать собственные метки индексов.
    *  Массив индексов - `index`,  названия колонок - `columns`.
    *  Гибкая структура, позволяющая легко изменять данные: добавлять/удалять колонки, обновлять значения и т.д.
    *  Возможность перестановки колонок и строк с помощью атрибута `T`.

## 2. Способы создания структур

### 2.1 Series

* **Из списка:**
    ```python
    s = pd.Series([12, -4, 7, 9])
    ```
* **Из словаря:**
    ```python
    data = {'a': 1, 'b': 2, 'c': 3}
    s = pd.Series(data) 
    ```
* **Из массива NumPy:**
    ```python
    import numpy as np
    arr = np.array([10, 20, 30, 40])
    s = pd.Series(arr) 
    ```
* **С заданными индексами:**
    ```python
    data = [1, 2, 3, 4]
    index = ['a', 'b', 'c', 'd']
    s = pd.Series(data, index=index)
    ```

### 2.2 DataFrame

* **Из словаря:**
    ```python
    data = {'color': ['blue', 'green', 'yellow'], 
            'object': ['ball', 'pen', 'pencil']}
    frame = pd.DataFrame(data) 
    ```
* **Из списка списков:**
    ```python
    data = [['blue', 'ball', 1.2], 
            ['green', 'pen', 1.0], 
            ['yellow', 'pencil', 0.6]]
    frame = pd.DataFrame(data, columns=['color', 'object', 'price'])
    ```
* **Из массива NumPy:**
    ```python
    import numpy as np
    arr = np.arange(16).reshape((4,4))
    frame = pd.DataFrame(arr)
    ```
* **Из другого DataFrame:**
    ```python
    new_frame = pd.DataFrame(frame)
    ```

## 3. Операции со структурами

### 3.1 Базовые операции

* **Доступ к элементам:**
    * `Series`:  `s[i]` - доступ по индексу, `s['label']` - доступ по метке.
    * `DataFrame`: `frame['column_name']` - доступ к колонке, `frame.loc['row_label']` - доступ к строке по метке, `frame.iloc[i]` - доступ к строке по числовому индексу.
* **Изменение значений:**
    * `s[i] = new_value`, `frame['column_name'][i] = new_value`.
* **Добавление/удаление элементов:**
    * `Series`:  `s.append(new_series)`, `s.drop(index)`.
    * `DataFrame`:  `frame['new_column'] = [values]`, `frame.drop('column_name', axis=1)`.
    * `Series`:  `s[i]` - доступ по индексу, `s['label']` - доступ по метке.
    * `DataFrame`: `frame['column_name']` - доступ к колонке, `frame.loc['row_label']` - доступ к строке по метке, `frame.iloc[i]` - доступ к строке по числовому индексу.
* **Изменение значений:**
    * `s[i] = new_value`, `frame['column_name'][i] = new_value`.
* **Добавление/удаление элементов:**
    * `Series`:  `s.append(new_series)`, `s.drop(index)`.
    * `DataFrame`:  `frame['new_column'] = [values]`, `frame.drop('column_name', axis=1)`.

### 3.2 Операции с двумя или более структурами

* **Слияние (Merge):**
    * `pd.merge(df1, df2, on='key')` - объединение DataFrame по общему ключу.
* **Соединение (Concat):**
    * `pd.concat([df1, df2], axis=0/1)` - объединение DataFrame по строкам (axis=0) или столбцам (axis=1).
* **Сводные таблицы (Pivot):**
    * `pd.pivot_table(df, values='value_column', index='index_column', columns='column_name')` - создание сводной таблицы.
