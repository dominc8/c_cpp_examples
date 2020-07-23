/* Constraints */
template <typename Cont>
  requires Sortable<Cont>()
void sort(Cont& container);

/* Same as above */
template <Sortable Cont>
void sort(Cont& container);


/* Axioms */
template<typename T>
axiom Greater(T x, T y)
{
  (x>y) == (y<x);
}

/* Concepts - combination of constraints and axioms */
concept Ordered<Regular T> {
  requires constraint Less<T>;
  requires axiom Strict_total_order<less<T>, T>;
  requires axiom Greater<T>;
  requires axiom Less_equal<T>;
  requires axiom Greater_equal<T>;
}

