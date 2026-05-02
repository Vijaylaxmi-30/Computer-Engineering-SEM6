import axios from "axios";
import { useEffect, useState } from "react";

function App() {
  const [tasks, setTasks] = useState([]);
  const [title, setTitle] = useState("");

  const [editId, setEditId] = useState(null);
  const [editText, setEditText] = useState("");

  // GET
  const fetchTasks = () => {
    axios.get("http://localhost:5000/api/tasks")
      .then(res => setTasks(res.data))
      .catch(err => console.log(err));
  };

  useEffect(() => {
    fetchTasks();
  }, []);

  // ADD
  const addTask = () => {
    if (!title.trim()) return;

    axios.post("http://localhost:5000/api/tasks", {
      title: title
    }).then(() => {
      setTitle("");
      fetchTasks();
    });
  };

  // DELETE
  const deleteTask = (id) => {
    axios.delete(`http://localhost:5000/api/tasks/${id}`)
      .then(() => fetchTasks());
  };

  // UPDATE
  const updateTask = (id) => {
    if (!editText.trim()) return;

    axios.put(`http://localhost:5000/api/tasks/${id}`, {
      title: editText
    }).then(() => {
      setEditId(null);
      setEditText("");
      fetchTasks();
    });
  };

  return (
    <div style={{ padding: "20px" }}>
      <h1>Task Manager</h1>

      <input
        value={title}
        onChange={(e) => setTitle(e.target.value)}
        placeholder="Enter task"
      />
      <button onClick={addTask}>Add</button>

      <hr />

      {tasks.map(task => (
        <div key={task._id} style={{ marginTop: "10px" }}>

          {editId === task._id ? (
            <>
              <input
                value={editText}
                onChange={(e) => setEditText(e.target.value)}
              />
              <button onClick={() => updateTask(task._id)}>Save</button>
              <button onClick={() => setEditId(null)}>Cancel</button>
            </>
          ) : (
            <>
              <span>{task.title}</span>
              <button onClick={() => {
                setEditId(task._id);
                setEditText(task.title);
              }}>
                Edit
              </button>
            </>
          )}

          <button onClick={() => deleteTask(task._id)}>Delete</button>

        </div>
      ))}
    </div>
  );
}

export default App;