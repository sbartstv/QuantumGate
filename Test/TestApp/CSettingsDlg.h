// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CSettingsDlg : public CDialogBase
{
	DECLARE_DYNAMIC(CSettingsDlg)

public:
	CSettingsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSettingsDlg();

	void SetStartupParameters(QuantumGate::StartupParameters* params) noexcept { m_StartupParameters = params; }

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();

private:
	QuantumGate::StartupParameters* m_StartupParameters{ nullptr };
public:
	afx_msg void OnBnClickedOk();
};
