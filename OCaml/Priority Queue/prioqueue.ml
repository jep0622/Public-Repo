(* Used ChatGPT because I didn't really understand a clever way to add priority to inserted items *)
type 'a pq = ('a * int) list


let empty : 'a pq = []

(* Empty check *)
let is_empty (pq : 'a pq) : bool =
  pq = []

(* Insert, assigns priority *)
let insert (elem : 'a) (priority : int) (pq : 'a pq) : 'a pq =
  let rec insert_helper elem priority = function
    | [] -> [(elem, priority)]
    | (e, p) as head :: tail ->
      if priority < p then
        (elem, priority) :: head :: tail
      else
        head :: (insert_helper elem priority tail)
  in
  insert_helper elem priority pq

(* Delete, deletes lowest prio *)
let remove_min (pq : 'a pq) : ('a * int) option * 'a pq =
  match pq with
  | [] -> (None, [])
  | (elem, priority) :: tail -> (Some (elem, priority), tail)

(* Main *)
let () =
  let pq = empty in
  let pq = insert "item 1" 2 pq in
  let pq = insert "item 2" 1 pq in
  let pq = insert "item 3" 3 pq in
  let (min_elem, pq) = remove_min pq in
  match min_elem with
  | Some (task, prio) -> Printf.printf "Removed: %s with priority %d
" task prio
  | None -> Printf.printf "Priority queue is empty
";
  
  (* Empty Check *)
  Printf.printf "Is empty? %b
" (is_empty pq)