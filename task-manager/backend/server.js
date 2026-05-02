const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

const app = express();

// middleware
app.use(cors());
app.use(express.json());

// routes
const taskRoutes = require('./routes/taskRoutes');
app.use('/api', taskRoutes);

// connect MongoDB
mongoose.connect("mongodb://127.0.0.1:27017/taskdb")
.then(() => console.log("MongoDB Connected"))
.catch(err => console.log(err));

// test route
app.get("/", (req, res) => {
  res.send("Backend running");
});

// start server
app.listen(5000, () => {
  console.log("Server running on port 5000");
});