const express = require('express');
const app = express();
const port = 3000;

// Middleware to parse JSON bodies
app.use(express.json());

// Mock save function
function save(user) {
    // In a real implementation, this function would save the user to a database
    // and return the saved user object
    return user;
}

// Custom error handling middleware
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).json({ error: "Internal server error" });
});

// Define the POST /users endpoint
app.post('/users', (req, res, next) => {
    try {
        // Parse the request body as JSON
        const data = req.body;

        // Validate the payload
        if (!data.name || !data.age) {
            res.status(400).json({ error: "Both 'name' and 'age' are required" });
            return;
        }

        const name = data.name;
        const age = data.age;

        if (typeof name !== 'string' || name.length > 32) {
            res.status(400).json({ error: "Invalid 'name' value" });
            return;
        }

        if (typeof age !== 'number' || age < 16) {
            res.status(400).json({ error: "Invalid 'age' value" });
            return;
        }

        // Create a user object
        const user = { name, age };

        // Call the save function
        const savedUser = save(user);

        // Return the saved user object with a 201 status code
        res.status(201).json(savedUser);
    } catch (error) {
        next(error); // Pass the error to the next middleware
    }
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
