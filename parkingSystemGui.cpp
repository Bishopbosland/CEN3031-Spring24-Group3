Add-Type -AssemblyName PresentationFramework
# Define XAML for the GUI
$xaml = @"
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="Parking Management System" Height="500" Width="800">
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="*"/>
        </Grid.RowDefinitions>


        <!-- Parking Space List -->
        <Label Grid.Row="0" Content="Parking Space List" Margin="10"/>
        <ListBox x:Name="parkingSpaceList" Grid.Row="1" Margin="10"/>


        <!-- Vehicle License Field -->
        <Label Grid.Row="2" Content="Vehicle License" Margin="10"/>
        <TextBox x:Name="vehicleLicenseField" Grid.Row="3" Margin="10"/>


        <!-- Buttons -->
        <StackPanel Grid.Row="4" Orientation="Horizontal" HorizontalAlignment="Center" Margin="10">
            <Button Content="Authorize" Width="100" Margin="5" Click="Authorize_Click"/>
            <Button Content="Assign Space" Width="100" Margin="5" Click="AssignSpace_Click"/>
            <Button Content="Mark Maintenance" Width="150" Margin="5" Click="MarkMaintenance_Click"/>
            <Button Content="Mark Available" Width="150" Margin="5" Click="MarkAvailable_Click"/>
        </StackPanel>
    </Grid>
</Window>
"@


# Load XAML
$reader = (New-Object System.Xml.XmlNodeReader $xaml)
$window = [Windows.Markup.XamlReader]::Load($reader)


# Get GUI elements
$parkingSpaceList = $window.FindName("parkingSpaceList")
$vehicleLicenseField = $window.FindName("vehicleLicenseField")


# Add event handlers
$window.Add_Loaded({
    # Initialize parking space list
    for ($i = 1; $i -le 10; $i++) {
        [void]$parkingSpaceList.Items.Add("Parking Space $i")
    }
})


$window.ShowDialog() | Out-Null


# Event handlers
function Authorize_Click {
    $license = $vehicleLicenseField.Text
    if (![string]::IsNullOrWhiteSpace($license)) {
        # Call parking_authorization.exe with vehicle license as argument
        $output = & ".\parking_authorization.exe" $license
        Write-Host $output
    } else {
        Write-Host "Please enter a vehicle license."
    }
}


function AssignSpace_Click {
    $license = $vehicleLicenseField.Text
    if (![string]::IsNullOrWhiteSpace($license)) {
        # Call parking_officer.exe with space ID and vehicle license as arguments
        $output = & ".\parking_officer.exe" $spaceID $license
        Write-Host $output
    } else {
        Write-Host "Please enter a vehicle license."
    }
}


function MarkMaintenance_Click {
    # Call parking_space.exe with space ID as argument
    $output = & ".\parking_space.exe" $spaceID
    Write-Host $output
}


function MarkAvailable_Click {
    # Call parking_space.exe with space ID as argument
    $output = & ".\parking_space.exe" $spaceID
    Write-Host $output
}

