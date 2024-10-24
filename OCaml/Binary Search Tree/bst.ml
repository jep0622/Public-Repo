(*ChatGPT was used to understand language syntax*)
type 'a bst =
  | Empty
  | Node of 'a * 'a bst * 'a bst

(* Insert function *)
let rec insert x tree =
  match tree with
  | Empty -> Node (x, Empty, Empty)
  | Node (value, left, right) ->
      if x < value then
        Node (value, insert x left, right)
      else if x > value then
        Node (value, left, insert x right)
      else
        tree 
        
(* Height function *)
let rec height tree =
  match tree with
  | Empty -> 0
  | Node (_, left, right) ->
      1 + max (height left) (height right)

(* Traversal function *)
let rec in_order_traversal tree =
  match tree with
  | Empty -> []
  | Node (value, left, right) ->
      (in_order_traversal left) @ [value] @ (in_order_traversal right)

(* Example usage *)
let () =
  let tree = Empty in
  let tree = insert 3 tree in
  let tree = insert 4 tree in
  let tree = insert 2 tree in
  let tree = insert 5 tree in
  let tree = insert 1 tree in

  Printf.printf "Height: %d
" (height tree);
  Printf.printf "Tree sorted least to greatest: %s
"
    (String.concat ", " (List.map string_of_int (in_order_traversal tree)))
