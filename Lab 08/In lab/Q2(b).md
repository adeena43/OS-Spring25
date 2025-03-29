
 b)
     Both threads calculate different values of counter due to a race condition. Since counter is shared, both threads try to update it at the same time. The     increment operation (counter = counter + 1) is not atomic, meaning:
     Both threads read the same value of counter.
     Both increment it separately without knowing about the other.
     One update gets lost, leading to incorrect results.
     Since thread execution is unpredictable, the final value of counter varies every time.
