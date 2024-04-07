import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.HashMap;
import java.util.Map;

public class ParkingSystemGUI extends JFrame {
    private JTextField licensePlateField;
    private JButton occupyButton;
    private JButton freeButton;
    private JTextArea statusArea;
    private Map<Integer, ParkingSpace> parkingSpaces;

    public ParkingSystemGUI() {
        setTitle("Parking System");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Initialize parking spaces
        parkingSpaces = new HashMap<>();
        for (int i = 1; i <= 10; i++) {
            parkingSpaces.put(i, new ParkingSpace(i));
        }

        // Create components
        JPanel inputPanel = new JPanel();
        JLabel licensePlateLabel = new JLabel("License Plate:");
        licensePlateField = new JTextField(10);
        occupyButton = new JButton("Occupy");
        freeButton = new JButton("Free");
        inputPanel.add(licensePlateLabel);
        inputPanel.add(licensePlateField);
        inputPanel.add(occupyButton);
        inputPanel.add(freeButton);

        statusArea = new JTextArea(10, 30);
        statusArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(statusArea);

        // Add components to the frame
        Container contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());
        contentPane.add(inputPanel, BorderLayout.NORTH);
        contentPane.add(scrollPane, BorderLayout.CENTER);

        // Add action listeners
        occupyButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String licensePlate = licensePlateField.getText();
                occupySpace(licensePlate);
            }
        });

        freeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                freeSpace();
            }
        });
    }

    private void occupySpace(String licensePlate) {
        boolean spaceFound = false;
        for (ParkingSpace space : parkingSpaces.values()) {
            if (!space.isOccupied() && !space.isUnderMaintenance()) {
                space.occupy(licensePlate);
                statusArea.append("Parking space " + space.getSpaceID() + " is now occupied by vehicle with license plate " + licensePlate + ".\n");
                spaceFound = true;
                break;
            }
        }
        if (!spaceFound) {
            statusArea.append("No available parking spaces.\n");
        }
    }

    private void freeSpace() {
        boolean spaceFound = false;
        for (ParkingSpace space : parkingSpaces.values()) {
            if (space.isOccupied()) {
                space.free();
                statusArea.append("Parking space " + space.getSpaceID() + " is now free.\n");
                spaceFound = true;
                break;
            }
        }
        if (!spaceFound) {
            statusArea.append("All parking spaces are already free.\n");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new ParkingSystemGUI().setVisible(true);
            }
        });
    }
}

class ParkingSpace {
    private int spaceID;
    private boolean occupied;
    private boolean underMaintenance;
    private String vehicleLicense;

    public ParkingSpace(int spaceID) {
        this.spaceID = spaceID;
        this.occupied = false;
        this.underMaintenance = false;
        this.vehicleLicense = "";
    }

    public void occupy(String licensePlate) {
        if (!occupied && !underMaintenance) {
            occupied = true;
            vehicleLicense = licensePlate;
        }
    }

    public void free() {
        if (occupied) {
            occupied = false;
            vehicleLicense = "";
        }
    }

    public int getSpaceID() {
        return spaceID;
    }

    public boolean isOccupied() {
        return occupied;
    }

    public boolean isUnderMaintenance() {
        return underMaintenance;
    }

    public String getVehicleLicense() {
        return vehicleLicense;
    }
}
