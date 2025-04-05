// Wait for the DOM to fully load
document.addEventListener("DOMContentLoaded", () => {
    // Set the initial background color
    document.body.style.backgroundColor = "#000000"; // Dark color

    // Animate to a lighter color
    let step = 0;
    const interval = setInterval(() => {
        step += 0.01; // Increment the brightness
        if (step >= 1) {
            clearInterval(interval); // Stop the animation
        }
        const colorValue = Math.floor(step * 255);
        document.body.style.backgroundColor = `rgb(${colorValue}, ${colorValue}, ${colorValue})`;
    }, 30); // Adjust the interval speed as needed
});